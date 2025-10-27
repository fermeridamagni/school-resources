# ✨ School Resources

A curated collection of study materials, hands-on practices, and code for multiple subjects. Built as a VitePress site for easy browsing and contribution.

## Highlights

- Organized by subjects with clear navigation and sidebars
- Practices include code (.ino, .c) and assets alongside documentation
- Consistent page templates and accessible content
- Automated formatting with Ultracite and Biome
- Ready to deploy to GitHub Pages

## Repository Structure

- `docs/` — Documentation site content
- `docs/.vitepress/` — Site configuration and theme
- `docs/subjects/` — Subject pages and practices
- `docs/subjects/<subject>/practices/<practice>/` — Individual practice pages and code
- `biome.jsonc`, `tsconfig.json` — Tooling configuration

## Get Started

- Prerequisites: Node.js 18+ and pnpm
- Install dependencies (optional; scripts use devDependencies):
  - pnpm install
- Start docs in dev mode:
  - pnpm docs:dev
- Build docs:
  - pnpm docs:build
- Preview built site:
  - pnpm docs:preview

## Contributing

- See the in-site Guide at `docs/guide/` or online at `/guide/`
- Follow accessibility and code-quality rules in `.github/instructions/ultracite.instructions.md`
- Run checks before pushing:
  - pnpm format:check
  - pnpm format:fix (optional, safe autofixes)

## Deployment

The site is configured for GitHub Pages deployment from `main` via CI. You can also push a built `docs/.vitepress/dist` to any static host.

## License

Apache-2.0 © fermeridamagni
