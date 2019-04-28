FROM php:7.1-cli

COPY ./extension /my-extension

RUN apt-get update
RUN apt-get install -y libgmp3-dev

COPY with-c-extension.php /scripts/with-c-extension.php
COPY pure-php.php /scripts/pure-php.php

RUN cd /my-extension && phpize
RUN cd /my-extension && ./configure
RUN cd /my-extension && make
RUN cd /my-extension && make install

RUN docker-php-ext-enable primecalc
RUN docker-php-ext-install bcmath