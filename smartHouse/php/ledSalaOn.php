<?php
    require('connection.php');

    $result= $con->exec("UPDATE componentes SET estado = 'on', fecha = CURRENT_DATE, hora = CURRENT_TIME WHERE id = 3");
    shell_exec("sudo python /var/www/html/smartHouse/python/ledSalaOn.py");
?>