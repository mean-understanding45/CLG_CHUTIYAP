<?php

session_start();
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Enter Details</title>
    </head>
    <body>
        <a href = "https://bit.ly/3huPRJJ"><h1>Click here to pay</h1></a>

        <div>
            <h3>
                <?php 
                    echo $_SESSION['success'];
                    unset($_SESSION['success']);
                ?>
            </h3>
        </div>

    </body>
</html>