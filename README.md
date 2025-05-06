# Arm-IoT

An embedded IoT project using ARM CMSIS for Raspberry Pi development.

## Overview

This project demonstrates embedded IoT development using:
- ARM CMSIS framework
- VS Code development environment
- GitHub Actions with ARM runners
- Raspberry Pi target platform

## Prerequisites

- VS Code with ARM development extensions
- CMSIS development tools
- Git
- (Optional) Raspberry Pi for deployment

## Getting Started

1. Clone this repository
2. Open the project in VS Code
3. Install recommended extensions
4. Build using provided GitHub Actions workflow

## Project Structure

```
.
├── .github/workflows    # CI/CD pipelines
├── src/                # Source code
├── include/            # Header files
├── tests/              # Unit tests
└── docs/              # Documentation
```

## Development

This project uses GitHub Actions for CI/CD with ARM runners. The workflow includes:
- Building for ARM architecture
- Running tests
- (Optional) Deployment to Raspberry Pi

## License

MIT License
