FROM debian:buster

# Config and install packages
RUN apt update
RUN apt install curl -y
RUN apt install vim -y

# SSL/TLS certificate generation
RUN mkdir -p /etc/nginx/ssl
RUN apt install OpenSSL -y
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=ldalmass.42.fr/UID=ldalmass"

# nginx
RUN apt install nginx -y
RUN mkdir -p /var/run/nginx

# Copy notre fichier conf hors du docker dans le docker
COPY conf/nginx.conf /etc/nginx/cong
