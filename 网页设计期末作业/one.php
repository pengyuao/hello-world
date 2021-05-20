<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php //文章页面
include"mysql.php";//执行mysql.php代码，即连接数据库
$sql="select * from `table`"; //sql查询语句
$res = mysqli_query($conn,$sql);//执行针对数据库的查询，第一个参数：规定要使用的 MySQL 连接，第二个参数：规定查询字符串
$conn = array();//创建数组
if($res && is_object($res)) //  检测变量$res是否是一个对象。
{
    while($row = mysqli_fetch_assoc($res)) //从结果集中取得一行作为关联数组
    {
        $data = $row['data'];//取出关联数组的data元素
        $num = $row['num'];//取出关联数组的num元素
        $time = $row['time'];//取出关联数组的time元素
        echo "<div style = 'border:1px solid #F00;'> 
        <p>内容: $data</p>
        <p>序列号: $num</p>
        <p>发布时间 $time</p>
        </div> ";//输出显示取出的data、num和time元素
       
    }
}
    ?>
    
</body>
</html>