---
title: Contributor Guide
---

## Overview

This guide explains how to work with this repository, add new content, and keep everything consistent.

## Quick Start

- Prerequisites: Node.js 18+, pnpm
- Install dependencies: pnpm install (optional; devDependencies are used by scripts)
- Start docs in dev mode: pnpm docs:dev
- Build docs: pnpm docs:build
- Preview build: pnpm docs:preview

## Repository Layout

- docs/ — Source for the documentation site (VitePress)
- docs/.vitepress/ — Site configuration and theme
- docs/subjects/ — Subject pages and practices
- docs/subjects/`<subject>`/practices/ — Practice pages and code
- README.md — Project overview

## Writing Pages

Each page should:

- Start with frontmatter containing at least a title
- Use clear heading hierarchy (H2+ in body; the page title is provided via frontmatter)
- Include a short overview paragraph
- Use ordered steps where applicable
- Link to code files and assets using relative paths

Example frontmatter:

```yaml
---
title: Practice 1 — PIC16F887 Digital I/O
description: Read digital inputs and control outputs on the PIC16F887
---
```

## Practice Page Template

- Overview: What you'll build and why
- Objectives: Bulleted list of learning goals
- Materials: Hardware and software list
- Circuit/Setup: Schematic or wiring instructions
- Steps: Numbered steps with short code excerpts if needed
- Run/Validation: What to observe and how to verify
- Troubleshooting: Common pitfalls
- References: Links to datasheets or docs

## Formatting & Linting

- Run format checks: pnpm format:check
- Auto-fix (safe): pnpm format:fix
- Diagnose formatting issues: pnpm format:doctor

## Adding a New Subject

1. Create a folder under `docs/subjects/<kebab-name>/`
2. Add an index.md with an overview and list of practices
3. Add practice folders under practices/
4. Add the subject and practices to the sidebar in docs/.vitepress/config.mts

## Adding a New Practice

1. Create `docs/subjects/<subject>/practices/<practice-name>/`
2. Add index.md following the practice template
3. Add code files (e.g., .ino, .c) and assets/ if needed
4. Link the practice in the subject's practices index and the sidebar

## Submitting Changes

- Keep PRs focused and small when possible
- Ensure docs build successfully and links work
- Follow accessibility and code-quality rules from `.github/instructions/ultracite.instructions.md`

## Deployment

Docs are deployed to GitHub Pages via CI on push to main. Local preview is available with pnpm docs:preview.
