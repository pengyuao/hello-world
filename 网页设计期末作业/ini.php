<!DOCTYPE html><!-- 首页页面-->
<html lang="en"> 
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    
    
</head>
<style>
*
{
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    font-family: 'Poppins',sans-serif;
    scroll-behavior: smooth;
}
body
{
    background: #111;
}
section
{
    position: relative;
    padding: 100px;
}
.header
{
    position: absolute;
    top:0;
    left: 0;
    z-index: 1000000;
    display: flex;
    justify-content: space-between;
    width: 100%;
    padding-top: 20px;
    padding-bottom: 20px;
}
.header .logo
{
    color: #fff;
    text-decoration: none;
    font-size: 1.2em;
}
.header .toggle img
{
    max-width: 40px;
    cursor: pointer;
}
.banner
{
    position: relative;
    width: 100%;
    min-height: 100vh;
    display: flex;
    justify-content: center;
    align-items: center;
    animation-name: animation;
    animation-duration: 4s;
    animation-iteration-count: 3;
}
@keyframes animation{
    from {background-color: black;}
    to{background-color: yellow;}
}
.banner:before
{
    content: '';
    position: absolute;
    bottom: 0;
    left: 0;
    width: 100%;
    height: 400px;
    z-index: 1;
    background: linear-gradient(to top,#111,transparent);
}
.banner .content
{
    position: relative;
    max-width: 900px;
    text-align: center;
    z-index: 1;
}
.banner .content h2
{
     color: #fff;
     font-size: 5em;
}
.banner .content p
{
     color: #fff;
     font-size: 1.2em;
}
.btn
{
    position: relative;
    display: inline-block;
    margin-top:30px;
    padding: 10px 30px;
    background: #fff;
    color: #333;
    text-decoration: none;
}
.fitBg
{
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    object-fit: cover;
    opacity: 0.8;
}

.about
{
    position: relative;
    width: 100%;
    display: flex;
    justify-content: center;
    align-items: center;
}

.about .contentBx
{
    min-width: 50%;
    width:50%;
    text-align: end; 
    padding-right: 40px;
}
.titleText
{
    font-weight: 600;
    color: #fff;
    font-size:2em;
    margin-bottom: 10px;
}
.text
{
    color:#fff;
    font-size: 1em;
}
.about .imgBx
{
    position: relative;
    min-width: 50%;
    width: 50%;
    min-height: 500px;
}
.banner2,
.banner3
{
    position: relative;
    width: 100%;
    min-height: 100vh;
    display: flex;
    justify-content: center;
    align-items: center;
}
.banner2:before,
.banner3:before
{
    content: '';
    position: absolute;
    bottom: 0;
    left: 0;
    width: 100%;
    height: 400px;
    z-index: 1;
    background: linear-gradient(to top,#111,transparent);
}
.banner2:after,
.banner3:after
{
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 400px;
    z-index: 1;
    background: linear-gradient(to bottom,#111,transparent);
}
.destination
{
    text-align: center;
}
.destination .content
{
    text-align: center;
}
.destination .destinationList
{
    position: relative;
    display: flex;
    justify-content: center;
    align-items: center;
    flex-wrap: wrap;
    margin-top: 40px;
}
.destination .destinationList .box 
{
    position: relative;
    min-width: 350px;
    height: 480px;
    background: #191919;
    transition: 0.5s;
    margin: 10px;
}
.destination .destinationList:hover .box /* 当鼠标放在三张图片的区域时，将三张图片都隐藏起来*/ 
{
    opacity: 0.2;
}
.destination .destinationList .box:hover/* 当鼠标放在其中一张图片时，将该图片突显出来*/ 
{
    opacity: 1;
}
.destination .destinationList .box .imgBx
{
    position: relative;
    width: 100%;
    height: 400px;
}
.destination .destinationList .box .content
{
    width: 100%;
    height: 80px;
    display: flex;
    justify-content: center;
    align-items: center;
}
.destination .destinationList .box .content h2
{
    color: #fff;
    font-weight: 500;
    line-height: 1.2em;
}
.destination .destinationList .box .content h2 span
{
    font-size: 0.8em;
    font-weight: 300;
    opacity: 0.5;
}
.footer
{
    display: flex;
    justify-content: center;
    align-items: center;
    flex-direction: column;

}
.footer .sci
{
    position: relative;
    display: flex;

}
.footer .sci .li a
{
    text-decoration: none;
    margin: 0 20px;
}
.footer .sci .li a img
{
    filter: invert(1);
    max-width: 40px;

}
.copyrightText
{
    margin-top: 20px;
    color: #fff;
    font-size: 18px;
    font-weight: 300;
    color: #666;
    text-align: center;
}
.copyrightText a
{
    color: #fff;
    text-decoration: none;
}
@media (max-width: 767px)
{
    section
    {
     
        padding: 40px;

    }
    .banner .content h2 
    {
       
        font: 2.5em;
    }
    .banner .content p
    {
       
        font: 1em;
    }
    .about
    {
      
        flex-direction: column;

    }
    .about .contentBx,
    .about .imgBx
    {
        min-width: 100%;
        width: 100%;
        text-align: center;
        padding-right: 0px;

    }
    .about .imgBx
    {
        min-height: 250px;

    }
    .btn
    {
        margin-bottom: 30px;
    }
    .destination .destinationList .box
    {
        position: relative;
        max-width: 350px;
        min-width: initial;
        width: 350px;
        height: 400px;
    }
    .destination .destinationList .box .imgBx
    {
        height: 320px;

    }
    .footer .sci li a img 
    {
        filter: invert(1);
        max-width: 30px;
    }

}
.javascript
{
    color:#fff;
    font-size: 1em;
}


</style>

<body>



    <section class="banner">
        <img src="./image3/2.jpg" class="fitBg" alt="">
        <div class="content">
            <h2>Write</h2>
            <p id="text1">Wenzhang includes works in various literary styles, such as poetry, drama,
                 fiction, scientific papers, narrative essays, argumentative essays, expository essays,
                  applied essays and so on. "Through the centuries the article is not done only", 
                  "the article is not written in life, and, therefore, superb", 
                  "the stool is to sit ten years cold, the article does not write a word empty", 
                  "the accumulation of chapters and become a chapter", "spoken for the theory, 
                  the pen is formed", etc., are now said in the meaning of the article, and, therefore,
                   superb. More broadly, the article also contains "knowledge" "mystery" and other
                    meaning, such as "insight of the world are all knowledge, human knowledge is the 
                    article" is.
            </p>
            <a href="#about" class="btn">Learn More</a> <!-- 超连接，转到Id为 about的内容-->
            <button type="button" onclick="myFunction()">翻译为中文</button><!-- 调用函数，将文字的内容修改为另一些文字-->
        </div>
    </section>

    <section class="about" id="about">
        <div class="contentBx">
            <h2 class="titleText">写作从现在开始</h2>
            <p class="text">1、文章的力量是不可估量的，写作可以带来感动是一方面，写作对于我们还有更重要的意义，想要展示自我时，最有说服力的手段莫过于写作。因此，不仅作家需要写作，从事其他行业的也同样需要写作。写得一手好文章，可提升自己的说服能力。
                            2、写作是也是一门艺术。能给人带来美的享受。
                            3、写作能提高语言的表达能力，进而能提高与人交际的能力。
                            4、通过写作还以提高悟性及理解能力。
                            5、有了悟性对学习理科或其他学科也都大有裨益。
                            6、语文若想考出好成绩，写好作文尤为重要。
                </p>
                <a href="#destination" class="btn">他人优秀的作品</a><!-- 超连接，转到Id为 destination的内容-->
        </div>
        <div class="imgBx">
            <img src="./image3/3.png" class="fitBg" alt="">
        </div>
    </section>

    <section class="banner2">
        <img src="./image3/4.jpg" class="fitBg" alt="">
    </section>

    <section class="destination" id="destination">
        <div class="content">
            <h2 class="titleText">
                    世界上最著名的文章
            </h2>
            <p class="text">Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod
                    tempor incididunt ut labore et dolore magna aliqua. ut enim ad minim veniam,
                    quis nostrud exercitation ullamco laboris nisi ut aliquip ex as commodo consequat
            </p>
        </div>
        <div class="destinationList">
            <div class="box">
                <div class="imgBx">
                    <img src="/image3/5.jpg" class="fitBg" alt="">

                </div>
                <div class="content">
                    <h2>Book One<br><span>战争与和平</span></h2>
                </div>
            </div>

            <div class="box">
                    <div class="imgBx">
                        <img src="/image3/6.jpg" class="fitBg" alt="">
    
                    </div>
                    <div class="content">
                        <h2>Book Two<br><span>巴黎圣母院</span></h2>
                    </div>
            </div>

            <div class="box">
                        <div class="imgBx">
                            <img src="/image3/7.jpg" class="fitBg" alt="">
        
                        </div>
                        <div class="content">
                            <h2>Book Three<br><span>童年</span></h2>
                        </div>
            </div>

        </div>
        <a href="#" class="btn">返回顶部</a><!-- 超连接，转到顶部的内容-->
    </section>
    <section class="banner3">
        <img src="./image1/banner3.jpg" class="fitBg" alt="">
    </section>

    <section class="footer">
        <ul class="sci">
            <li><a href="#"><img src="/image1/facebook.png" alt=""></a></li><!-- 超连接，转到顶部的内容-->
            <li><a href="#"><img src="/image1/twitter.png" alt=""></a></li><!-- 超连接，转到顶部的内容-->
            <li><a href="#"><img src="/image1/instagram.png" alt=""></a></li><!-- 超连接，转到顶部的内容-->
        </ul>
        <h4 class="copyrightText">Copyright  2020 <a href="#">Online Tutorials</a>.All rights</h4><!-- 超连接，转到顶部的内容-->
    </section>


    
    <script>
        function myFunction(){
            document.getElementById("text1").innerHTML = "《文章》包括各种文体的著作、作品，如诗歌、戏剧、小说、科学论文，记叙文、议论文、说明文、应用文等等。“千古文章未尽才”“文章千古事”“文章憎命达”“板凳要坐十年冷、文章不写一字空”“积句而成章，积章而成篇”“言出为论，下笔成章”等，都是现在所说的文章的意思。更广义的文章，也包含“学问”“奥秘”等意思，如“洞明世事皆学问，人情练达即文章”就是。";
        }//将文字内容进行修改
      
    </script>


</body>
</html> 