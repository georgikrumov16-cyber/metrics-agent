📌 Overview
DMAP (DevOps Monitoring & Automation Platform) is a fully containerised, Kubernetes‑native monitoring system designed to collect, expose, scrape, and visualise system metrics using:

A custom-built metrics agent

Docker for containerisation

Kubernetes for orchestration

Prometheus Operator for scraping and alerting

Grafana for dashboards

Helm for packaging

GitHub Actions for CI/CD

This project demonstrates real‑world DevOps skills including infrastructure automation, observability, CI/CD pipelines, containerisation, and cloud‑native architecture.

🚀 Features
🔹 Custom Metrics Agent
Collects:

CPU usage

Memory usage

Disk usage

Custom system metrics

Exposes metrics via HTTP in Prometheus format.

🔹 Kubernetes Deployment
Deployment

Service

ServiceMonitor

Optional Ingress

🔹 Prometheus Integration
Automatic scraping via ServiceMonitor

Custom scrape intervals

Optional alert rules

🔹 Grafana Dashboards
CPU usage

Memory usage

Disk usage

Node metrics

Custom agent metrics

🔹 CI/CD Pipeline
GitHub Actions pipeline includes:

Build

Test

Docker image build

Push to GHCR

Helm lint

Optional auto‑deploy to k3d

🔹 Helm Chart
Fully templated

Configurable values

Production‑ready structure

🏗️ Architecture
Code
+-------------------+        +---------------------+
|   Metrics Agent   | -----> |     Prometheus      |
| (C++ / Python)    |        | (Operator Managed)  |
+-------------------+        +---------------------+
           |                           |
           |                           v
           |                   +----------------+
           |                   |    Grafana     |
           |                   |   Dashboards   |
           |                   +----------------+
           |
           v
+-------------------+
|   Kubernetes      |
| (k3d / Cloud)     |
+-------------------+
🛠️ Tech Stack
Component	Technology
Metrics Agent	C++ / Python
Containerisation	Docker
Orchestration	Kubernetes (k3d)
Monitoring	Prometheus Operator
Visualisation	Grafana
Packaging	Helm
CI/CD	GitHub Actions
Registry	GHCR


📦 Local Development (k3d)
Create cluster
bash
k3d cluster create dmap --servers 1 --agents 2
Import image
bash
k3d image import metrics-agent:latest -c dmap
Deploy
bash
kubectl apply -f deployment.yaml
kubectl apply -f service.yaml
kubectl apply -f servicemonitor.yaml
📊 Grafana Dashboard
Access Grafana:

bash
kubectl port-forward -n monitoring svc/monitoring-grafana 3000:80
Open:

Code
http://localhost:3000
Dashboard includes:

CPU usage

Memory usage

Disk usage

Node metrics

Custom agent metrics

🔄 CI/CD Pipeline
GitHub Actions pipeline includes:

Build & test metrics agent

Build Docker image

Push to GHCR

Helm lint

Optional: deploy to k3d

📁 Repository Structure
Code
.
├── src/
├── include/
├── Dockerfile
├── deployment.yaml
├── service.yaml
├── servicemonitor.yaml
├── charts/
│   └── dmap/
├── .github/workflows/
│   └── ci.yaml
└── README.md
🧠 What I Learned 
Working on this project taught me a lot about how I think and work as an engineer. I realised how much I enjoy breaking down complex systems into smaller, understandable pieces — and then putting them back together in a clean, reliable way.

I learned how important it is to stay patient when things go wrong, especially with Kubernetes and networking. Every issue forced me to understand the system more deeply instead of just applying quick fixes.

I also discovered that I really enjoy building things that are observable. Seeing my own metrics appear in Prometheus and Grafana felt like a milestone — it made the project feel real, not just theoretical.

Most importantly, this project showed me that I can take an idea from nothing to a working, production‑style system, even when the path isn’t straightforward. It gave me confidence in my ability to learn, troubleshoot, and build things that actually matter.

👤 Author
Georgi Krumov 
Junior DevOps & Software Engineering Professional
Hampshire, UK
