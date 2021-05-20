<?php
$num = $_SERVER{'QUERY_STRING'}; //获取网址后面的参数
$nums = substr($num,0,2);//将参数变为数组取前两个
if ($nums == 'WZ')
{
    include "one.php";//进入文章页面
}
else if($nums != 'WZ' && $nums != 'FW')
{
    include "ini.php";//进入首页页面
}
else if($nums == 'FW')
{
    include "post.php";//进入发文页面
}

?>