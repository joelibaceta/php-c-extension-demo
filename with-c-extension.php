<?php

$start = microtime(true);
$counter = 0;
for ($i = 123456789012; $counter <= 10000; $i++) {
    if (miller_rabin($i)) {
        $str_counter = str_pad($counter, 5, "0", STR_PAD_LEFT);
        echo "{$str_counter} Primes founded: \t Last Prime: {$i} \r";
        $counter++;
    }
}

echo "\n";
echo "elapsed: " . (microtime(true) - $start) . "\n";

?>