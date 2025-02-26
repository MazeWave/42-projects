FROM alpine:3.20.0

# Config and install packages
RUN apk update
RUN apk add curl -q
RUN apk add vim -q
RUN curl --version
RUN vim --version


# SSL/TLS certificate generation
RUN mkdir -p /etc/nginx/ssl
RUN apk add openssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=ldalmass.42.fr/UID=ldalmass"

# nginx
RUN apk add nginx
RUN mkdir -p /var/run/nginx

# Copy notre fichier conf hors du docker dans le docker
COPY conf/nginx.conf /etc/nginx/conf

