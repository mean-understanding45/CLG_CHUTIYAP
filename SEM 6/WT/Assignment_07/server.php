<?php

session_start();

//initialising variables

$errors = array();

// connect to database

$db = mysqli_connect('localhost', 'root', 'Tejas@2212', 'anscoach') or die("could not connect to database");

// register user ...

$name = mysqli_real_escape_string($db, $_POST['name']);
$email = mysqli_real_escape_string($db, $_POST['email']);
$phone = mysqli_real_escape_string($db, $_POST['phone']);

// form validation ...

if(empty($name)) {array_push($errors, "Name is required");}
if(empty($email)) {array_push($errors, "Email is required");}
if(empty($phone)) {array_push($errors, "Phone is required");}

// register user if no error ...

if(count($errors) == 0){
    $query = "INSERT INTO details(nameOf, email, phone) values ($name, $email, $phone)";
    mysqli_query($db, $query);

    $_SESSION['name'] = $name;
    $_SESSION['success'] = "You are now registered";

    header('location: index.php');
}