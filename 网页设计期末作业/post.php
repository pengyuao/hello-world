<!DOCTYPE html><!-- 发文页面-->
<html lang="en">
<head>
   
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="posting.php" method="post"> <!-- 发送表单数据到posting.php-->
        <div align="center">
            <p>内容：<input type="text" name = "data"/></p>
            <p>序列号：<input type="text" name = "num" value="<?php echo rand(10000,90000);?>"/></p>
            <p>时间：<input type="text" name = "time" value="<?php echo date("Y/m/d");?>"/></p>
            <input type="submit">
            
        </div>
    </form>
</body>
</html>