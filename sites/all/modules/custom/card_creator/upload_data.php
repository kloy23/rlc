<?php
  define('UPLOAD_DIR', 'localhost/rlcdev/sites/default/files/user_business_cards/');
  $img = $_POST['img'];
  $img = str_replace('data:image/png;base64,', '', $img);
  $img = str_replace(' ', '+', $img);
  $data = base64_decode($img);
  $file = UPLOAD_DIR . uniqid() . '.png';
  $success = file_put_contents($file, $data);
  print $success ? $file : 'Unable to save the file.';




