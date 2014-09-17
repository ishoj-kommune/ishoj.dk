
<!--  TOP CONTENT START -->
<div class="content-top box noMargin"><?php print $content['content-top']; ?></div>
<!--  TOP CONTENT END -->

<!-- TEASER TARGET START -->
<section class="teaserWrapTarget box">
	<div class="teaserTarget"></div>
</section>
<!-- TEASER TARGET END -->

<!-- TEASER START -->		
<section class="teaserWrap box">
	<div class="flexslider">
		<ul class="teaser slides">
			<?php print $content['selvbetjening']; ?>
        </ul>
        
        
        <nav id="teaserNav" class="flex-control-nav flex-control-paging">
            <ul>
                <li class="teaserBtn01 round3"><a class="teaserNavActive" href="#" title="Selvbetjening"></a></li>
                <li class="teaserBtn02 round3"><a href="#" title="Selvbetjening"></a></li>
                <li class="teaserBtn03 round3"><a href="#" title="Selvbetjening"></a></li>
                <!--<li class="teaserBtn04 round3"><a href="#" title="Selvbetjening"></a></li>-->
            </ul>
        </nav>

    </div>
</section>
<!-- TEASER END -->

<!-- FRONT LEFT START -->
<div class="frontLeft"> 
	<div class="frontLeftCol1"><?php print $content['left']; ?></div>                    
	<div class="frontFiller box"></div>
</div>
<!-- FRONT LEFT END -->

<!-- FRONT RIGHT START -->
<div class="frontRight">
	<div class="frontRightCol1"><?php print $content['right1dob']; ?></div>
	<div class="frontRightCol2"><?php print $content['right2single']; ?></div>
	<div class="frontRightCol1"><?php print $content['right3dob']; ?></div>
	<div class="frontRightCol2"><?php print $content['right4single']; ?></div>
	<div class="frontRightCol2 target"></div>
</div>
<!-- FRONT RIGHT END -->


