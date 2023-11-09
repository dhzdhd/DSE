<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    $json = '[
        {"name": "John", "age": 30, "city": "New York"},
        {"name": "Peter", "age": 40, "city": "Los Angeles"}
    ]';

    $data = json_decode($json, true);

    echo "<table border='1'>";
    echo "<tr><th>Name</th><th>Age</th><th>City</th></tr>";
    foreach ($data as $item) {
        echo "<tr>";
        echo "<td>" . $item['name'] . "</td>";
        echo "<td>" . $item['age'] . "</td>";
        echo "<td>" . $item['city'] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
    ?>

</body>

</html>
