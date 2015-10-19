<?php

$a= array(5,4,3,2,1);
$b= array();
$c= array();
transfer(sizeof($a), $a, $b, $c);
var_dump($a);
var_dump($b);
var_dump($c);
function transfer($n,&$source,&$destination,&$spare){
  if($n == 1){
    array_push($destination, array_pop($source));
    return;
  }
  transfer($n-1, $source, $spare, $destination);
  transfer(1, $source, $destination);
  transfer($n-1, $spare, $destination, $source);
}