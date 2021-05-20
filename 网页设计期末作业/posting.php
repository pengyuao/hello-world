<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?php
    include"mysql.php";
    $data = $_POST['data']; // $_POST 变量用于收集来自 method="post" 的表单中的值
    $num = $_POST['num'];
    $time = $_POST['time'];
    if($data == "" || $num == "" || $time == "")
    {
        echo"<script>alert('信息不可为空!');history.back();</script> ";
    }
    else
    {
        $selsql = "select * from `table` where num = '$num'";
        $selres=mysqli_query($conn,$selsql);//执行针对数据库的查询，第一个参数：规定要使用的 MySQL 连接，第二个参数：规定查询字符串
       
      
       $selrow=mysqli_fetch_object($selres);//返回结果集中的当前行
      
      
         if ($selrow)
       {
        echo"<script>alert('此文章已经存在！');history.back();</script>";
       }
         else
        {
        
        mysqli_query($conn,"SET NAMES uft8");
       
        $inssql = "insert into `table`(data,num,time) values('$data','$num','$time')";
        mysqli_query($conn,"SET NAMES uft8");
       
        $insres =mysqli_query($conn,$inssql);//执行针对数据库的插入
       
         if($insres)
         {
             echo"<script>alert('发布成功！');history.go(-2);</script>";
         }
         else
         {
             echo"<script>alert('发布失败！');</script>";
         }

        }
    }
?>