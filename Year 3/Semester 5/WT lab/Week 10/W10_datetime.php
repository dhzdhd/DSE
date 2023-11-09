<?php
$cookie_name = "lastVisit";
date_default_timezone_set('UTC');
$cookie_value = date("Y-m-d H:i:s");

setcookie($cookie_name, $cookie_value, time() + (86400 * 30), "/"); // 86400 = 1 day
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php

    if (!isset($_COOKIE[$cookie_name])) {
        echo "Welcome to our website! This is your first visit.";
    } else {
        echo "Welcome back! You last visited on " . $_COOKIE[$cookie_name];
    }
    ?>
</body>

</html>
