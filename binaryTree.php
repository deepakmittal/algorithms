<?php



class Node{
  public $data;
  public $left;
  public $right; 
}

function add(&$root,$data){
 	if($root==NULL){
 		$root = new Node();
		$root->data = $data;
		$root->left = NULL;
		$root->right =  NULL;
		return;	
 	}
	if($data < $root->data)
		add($root->left,$data);
	else
		add($root->right,$data);
	
	
}
function inorder($root){
	if($root != NULL){
		inorder($root->left);
		echo ">> " . $root->data;
		inorder($root->right);
	}
}  

function zigZag($root){
	$even=array($root);
	$odd=array();
	while($even || $odd){
		while($even){
			$a=array_shift($even);
			echo $a->data;
			if($a->left)
				array_push($odd, $a->left);
			if($a->right)	
				array_push($odd, $a->right);
		}
		while($odd){
                        $a=array_pop($odd);
                        echo $a->data;
                        if($a->right)
                                array_unshift($even, $a->right);
                        if($a->left)   
                                array_unshift($even, $a->left);
                }
		


	}
	

}

$root = NULL;

add($root,6);
add($root,5);
add($root,9);
add($root,3);
add($root,1);
add($root,4);
add($root,7);
add($root,8);

inorder($root);
zigZag($root);



