<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $target_dir = "uploads/";
    $target_file = $target_dir . basename($_FILES["resume"]["name"]);

    $uploadOk = true;
    $fileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));

    if ($fileType != "pdf") {
        echo "Sorry, only PDF files are allowed.";
        $uploadOk = false;
    }

    move_uploaded_file($_FILES["resume"]["tmp_name"], $target_file);
    echo "The file " . htmlspecialchars(basename($_FILES["resume"]["name"])) . " has been uploaded.";
}
?>

<!DOCTYPE html>
<html>

<body>
    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post" enctype="multipart/form-data">
        Select PDF file to upload:
        <input type="file" name="resume" id="resume">
        <input type="submit" value="Upload" name="submit">
    </form>
</body>

</html>
