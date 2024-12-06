<?php
    require('connection.php');

    $result= $con->exec("UPDATE componentes SET estado = 'off', fecha = CURRENT_DATE, hora = CURRENT_TIME WHERE id = 3");
    shell_exec("sudo python /var/www/html/smartHouse/python/ledSalaOff.py");
?>
