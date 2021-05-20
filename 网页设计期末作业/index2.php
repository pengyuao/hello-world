<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<style type="text/css">
*{
    margin:0;
    padding:0;
}
li
{
    
    
    float:left; 
    list-style:none;
}
</style>
<body>
    <div style="width:80%;">
        <div align="center">
            <ul>
               <li><a href="?" ><input type="button" style ="height:50px;
               width:300px; background-color:#F60; font:25px;" value="首页"> </a>  </li> <!-- 网页网址不变 -->
               <li><a href="?WZ" ><input type="button" style ="height:50px;
               width:300px; background-color:#F60; font:25px;" value="文章"> </a>  </li><!-- 网页网址后面加上WZ -->
               <li><a href="?FW" ><input type="button" style ="height:50px;
               width:300px; background-color:#F60; font:25px;" value="发文"> </a>  </li><!-- 网页网址后面加上FW -->
               
            </ul>
            
        </div>
    </div>
<br /><br /><br />
    <?php
    include "indexs.php"; //执行indexs.php文件代码，作用是根据网页的网址，判断进入那个页面
    ?>
</body>
</html>