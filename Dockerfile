FROM gcc:latest
ENV MQTT_HOST
ENV MQTT_PORT=1883

ADD . /app
WORKDIR /app/build

RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      libgtest-dev \
      cmake \
      linux-perf

RUN cmake .. && make

CMD ./mmbwmon --server $MQTT_HOST --port $MQTT_PORT
