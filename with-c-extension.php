<?php

echo "Using a C extension \n\n";

$start = microtime(true);
$counter = 0;
for ($i = 100000000000; $counter <= 5000; $i++) {
    if (miller_rabin($i)) {
        $str_counter = str_pad($counter, 5, "0", STR_PAD_LEFT);
        echo "{$str_counter} Primes founded: \r";
        $counter++;
    }
}

echo "\n";
echo "elapsed: " . (microtime(true) - $start) . "\n";

?>