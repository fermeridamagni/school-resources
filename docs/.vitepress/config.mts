import { defineConfig } from "vitepress";

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "✨ School Resources",
  description:
    "A collection of educational materials and resources for various subjects and courses related to all my school work.",
  base: "/school-resources/",

  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: "Home", link: "/" },
      { text: "Subjects", link: "/subjects" },
    ],

    sidebar: [
      {
        base: "/subjects",
        text: "Subjects",
        items: [
          {
            text: "Design of Mechanisms Assisted by Computer",
            link: "/design-of-mechanisms-assisted-by-computer",
            items: [
              {
                base: "/subjects/design-of-mechanisms-assisted-by-computer/cad-exercises",
                text: "CAD Exercises",
                link: "/cad-exercises",
                items: [
                  {
                    text: "Practice 1 - Solid Edge",
                    link: "/practice-1-solid-edge",
                  },
                  {
                    text: "Practice 2 - Solid Edge",
                    link: "/practice-2-solid-edge",
                  },
                  {
                    text: "Practice 3 - Solid Edge",
                    link: "/practice-3-solid-edge",
                  },
                  {
                    text: "Practice 4 - Solid Edge",
                    link: "/practice-4-solid-edge",
                  },
                  {
                    text: "Practice 5 - Solid Edge",
                    link: "/practice-5-solid-edge",
                  },
                  {
                    text: "Practice 6 - Solid Edge",
                    link: "/practice-6-solid-edge",
                  },
                ],
              },
            ],
            collapsed: true,
          },
          {
            text: "Electronic Sensors and Actuators",
            link: "/electronic-sensors-and-actuators",
            items: [
              {
                text: "Practices",
                base: "/subjects/electronic-sensors-and-actuators/practices",
                link: "/practices",
                items: [
                  {
                    text: "Practice - Object Counter with Ultrasonic Sensor",
                    link: "/practice-1-object-counter",
                  },
                  {
                    text: "Practice - Water Level Monitor",
                    link: "/practice-2-water-level-monitor",
                  },
                ],
              },
            ],
            collapsed: true,
          },
          {
            text: "Industrial Robotics",
            link: "/industrial-robotics",
            items: [],
            collapsed: true,
          },
          {
            text: "Programmable Logic Devices",
            link: "/programmable-logic-devices",
            items: [],
            collapsed: true,
          },
        ],
      },
    ],

    footer: {
      message: "Released under the Apache-2.0 License.",
      copyright: "Copyright © 2023 fermeridamagni",
    },

    socialLinks: [
      { icon: "github", link: "https://github.com/vuejs/vitepress" },
    ],

    search: {
      provider: "local",
    },
  },
});
