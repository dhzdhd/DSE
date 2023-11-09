<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    session_start();

    $employees = array(
        array("name" => "John", "age" => 30, "city" => "New York"),
        array("name" => "Jane", "age" => 35, "city" => "Chicago"),
        array("name" => "Peter", "age" => 40, "city" => "Los Angeles")
    );

    $_SESSION['employees'] = $employees;

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $ename = $_POST["ename"];
        $found = false;

        foreach ($_SESSION['employees'] as $employee) {
            if ($employee["name"] == $ename) {
                echo "Name: " . $employee["name"] . "<br>";
                echo "Age: " . $employee["age"] . "<br>";
                echo "City: " . $employee["city"] . "<br>";
                $found = true;
                break;
            }
        }

        if (!$found) {
            echo "No employee found with the given name.";
        }
    }
    ?>

    <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
        Name: <input type="text" name="ename">
        <input type="submit">
    </form>

</body>

</html>
