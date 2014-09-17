<?php

/**
 * @file
 * Site controller class.
 */

class SiteController {

  /**
   * Gets current site from context.
   *
   * @todo  Replace current instances of sites_get_current_site with this.
   */
  public static function getCurrentSite() {
    return unserialize(context_get('sites', 'site'));
  }

  /**
   * Gets all sites.
   *
   * @return array
   *   List of sites.
   */
  public static function getSites() {
    $sites = array();

    $results = db_select('sites', 's')
                 ->fields('s')
                 ->execute();

    while ($site_raw_data = $results->fetchObject()) {
      $sites[] = SiteController::createSiteFromRawData($site_raw_data);
    }

    return $sites;
  }

  /**
   * Gets a single site.
   *
   * @param int $site_id
   *   The site ID.
   *
   * @return
   *   Site object or false when no site was found.
   */
  public static function getSite($site_id) {
    if (empty($site_id)) {
      return FALSE;
    }

    // Get site data from database.
    $result = db_select('sites', 's')
              ->fields('s')
              ->condition('sid', $site_id)
              ->execute()
              ->fetchObject();

    // Convert the raw database result to a Site instance.
    $site = self::createSiteFromRawData($result);

    if (empty($site->sid)) {
      return FALSE;
    }

    return $site;
  }

  /**
   * Gets a single site by purl_prefix.
   *
   * @todo  refactor to something like getSiteByProperty().
   *
   * @param string $purl_prefix
   *   The site's purl prefix.
   *
   * @return
   *   Site object or false when no site was found.
   */
  public static function getSiteByPrefix($purl_prefix) {
    if (empty($purl_prefix)) {
      return FALSE;
    }

    // Get site data from database.
    $result = db_select('sites', 's')
              ->fields('s')
              ->condition('sid', $site_id)
              ->execute()
              ->fetchObject();

    // Convert the raw database result to a Site instance.
    $site = self::createSiteFromRawData($result);

    if (empty($site->sid)) {
      return FALSE;
    }

    return $site;
  }

  /**
   * Get the site(s) that a given node belongs to.
   *
   * @param int $node
   *   A node ID.
   *
   * @return $sites
   *   Array of site information.
   */
  public static function getSitesByNode($nid) {
    $sites = array();

    $results = db_select('site_node', 's')
              ->join('purl', 'p', 's.sid = p.id')
              ->fields('s')
              ->fields('p')
              ->condition('nid', $nid)
              ->execute();

    while ($site = $results->fetchObject()) {
      $sites[] = $site;
    }

    return $sites;
  }

  /**
   * Deletes a site and all it's resources.
   *
   * @param int $site_id
   *   Site ID.
   */
  public static function deleteSite($site_id) {
    $site = self::getSite($site_id);

    // Delete corresponding row from sites table.
    db_delete('sites')
      ->condition('sid', $site_id)
      ->execute();
    // Delete site node information.
    db_delete('site_node')
      ->condition('sid', $site_id)
      ->execute();
    // delete PURL prefix
    purl_delete(array(
      'provider' => 'sites',
      'id' => $site_id,
    ));
    // Delete site's resources.
    SiteResourcesController::deleteResources($site);
  }

  /**
   * Gets the current theme if there is a site active.
   *
   * @return string
   *   Theme name or false if no subsite is active.
   */
  public static function getCurrentTheme() {
    // Determine current purl prefix.
    $purl_prefix = arg(0);
    if (! self::isSitePurlModifier($purl_prefix)) {
      return FALSE;
    }

    return db_select('sites', 's')
      ->fields('s', array('theme'))
      ->condition('purl_prefix', $purl_prefix)
      ->execute()
      ->fetchColumn();
  }

  /**
   * Shows an overview page of all the sites.
   */
  public static function pageAdminOverview() {
    $table_info = self::getSitesTableInfo();
    $rows = array();
    $current_site = self::getCurrentSite();

    // Iterate through the sites and build the table rows.
    foreach ($table_info['results'] as $site) {
      purl_disable(TRUE);
      $operation_links = self::getOperationLinks($site);
      $rows[] = array(
        'data' => array(l($site->name, $site->purl_prefix), $site->title, $site->purl_prefix, $operation_links['edit'] . ' ' . $operation_links['delete'])
      );
    }

    // Build the output.
    $output = theme('table', array('header' => $table_info['header'], 'rows' => $rows, 'caption' => '', 'sticky' => TRUE, 'empty' => t("You haven't created any sites yet.")));
    // Add the pager.
    $output .= theme('pager', array('tags' => array()));

    return $output;
  }

  /**
   * Determins if a path is a purl modifier used by sites.
   */
  public static function isSitePurlModifier($path = NULL) {
    // Determine path to check.
    $purl_prefix = ($path === NULL) ? arg(0) : $path;
    $modifier_to_fetch = array('value' => $purl_prefix, 'provider' => 'sites');
    // Try to load the purl modifier.
    $modifier = purl_load($modifier_to_fetch);
    if ($modifier == FALSE) {
      return FALSE;
    }
    return $modifier;
  }

  /**
   * Gets a list of sites meant to be used in a sortable, paged table.
   */
  protected static function getSitesTableInfo() {
    // Build the table header: Name | Title | Url | Actions.
    $header = array(
      array('data' => 'Name', 'field' => 'name', 'sort' => 'asc',),
      array('data' => 'Title', 'field' => 'title',),
      array('data' => 'Url', 'field' => 'purl_prefix',),
      array('data' => ''),
    );

    // Build a query with pager and tablesorting.
    $query = db_select('sites', 's');
    $results = $query
      ->extend('PagerDefault')
      ->extend('TableSort')
      ->limit(10)
      ->orderByHeader($header)
      ->fields('s', array('sid', 'name', 'title', 'purl_prefix',))
      ->execute();

    return array('results' => $results, 'header' => $header, 'query' => $query);
  }

  /**
   * Gets a list of operation links for a given site.
   */
  protected static function getOperationLinks($site) {
    $operation_links = array();
    $current_site = self::getCurrentSite();

    // We're not currently in any subsite context.
    if (empty($current_site)) {
      $operation_links['edit']    = l(t('edit'), 'admin/structure/sites/edit/' . $site->sid);
      $operation_links['delete']  = l(t('delete'), 'admin/structure/sites/delete/' . $site->sid);
      $operation_links['add']     = l(t('Add a new site'), 'admin/structure/sites/add');
    }
    else {
      $operation_links['edit']    = l(t('edit'), $current_site->purl_prefix . '/admin/structure/sites/edit/' . $site->sid);
      $operation_links['delete']  = l(t('delete'), $current_site->purl_prefix . '/admin/structure/sites/delete/' . $site->sid);
      $operation_links['add']     = l(t('Add a new site'), $current_site->purl_prefix . '/admin/structure/sites/add');
    }

    return $operation_links;
  }

  /**
   * Creates a site object based on raw data.
   */
  protected static function createSiteFromRawData($raw_data) {
    $properties = array('sid', 'purl_prefix', 'title', 'name', 'front_page', 'menu_main_menu', 'menu_secondary_menu', 'theme');
    $site = new Site();
    if (is_array($raw_data)) {
      foreach ($properties as $property) {
        if (isset($raw_data[$property])) {
          $site->$property = $raw_data[$property];
        }
      }
    }
    else if (is_object($raw_data)) {
      foreach ($properties as $property) {
        if (isset($raw_data->$property)) {
          $site->$property = $raw_data->$property;
        }
      }
    }
    return $site;
  }
}
