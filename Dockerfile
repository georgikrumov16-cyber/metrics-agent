FROM ubuntu:22.04

# Install dependencies
RUN apt update && apt install -y g++ make wget curl

# Create app directory
WORKDIR /app

# Copy source code
COPY src/ ./src/
COPY include/ ./include/

# Build the metrics agent
RUN g++ src/main.cpp -o metrics-agent -Iinclude -pthread

# Expose the REST API port
EXPOSE 8080

# Run the agent
CMD ["./metrics-agent"]
