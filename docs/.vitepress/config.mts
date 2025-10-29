import { defineConfig } from "vitepress";

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "✨ School Resources",
  description:
    "A collection of educational materials and resources for various subjects and courses related to all my school work.",
  base: "/school-resources/",
  lastUpdated: true,

  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: "Home", link: "/" },
      { text: "Subjects", link: "/subjects" },
      { text: "Guide", link: "/guide/" },
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
            items: [
              {
                text: "Practices",
                base: "/subjects/programmable-logic-devices/practices",
                link: "/practices",
                items: [
                  {
                    text: "Practice 1 - PIC16F887 Digital I/O",
                    link: "/practice-1-pic16f887-digital-io",
                  },
                  {
                    text: "Practice 2 - PIC16F887 Analog I/O",
                    link: "/practice-2-pic16f887-analog-io",
                  },
                  {
                    text: "Practice 3 - ESP32 House Alarm",
                    link: "/practice-3-esp32-house-alarm",
                  },
                  {
                    text: "Practice 4 - Arduino Buzzers",
                    link: "/practice-4-arduino-and-buzzers",
                  },
                  {
                    text: "Practice 5 - Arduino IR Sensor",
                    link: "/practice-5-arduino-ir-sensor",
                  },
                  {
                    text: "Practice 6 - Arduino Traffic Light",
                    link: "/practice-6-arduino-traffic-light",
                  },
                  {
                    text: "Practice 7 - Arduino Led Intermitence",
                    link: "/practice-7-arduino-led-intermitence",
                  },
{
                    text: "Practice 8 - Arduino R4 Bluetooth",
                    link: "/practice-8-arduino-r4-bluetooth",
                  },
                  {
                    text: "Practice 9 - Arduino Button and Engine",
                    link: "/practice-9-arduino-button-and-engine",
                  },
                ],
              },
            ],
            collapsed: true,
          },
        ],
      },
    ],

    footer: {
      message: "Released under the Apache-2.0 License.",
      copyright: "Copyright © 2025 fermeridamagni",
    },

    socialLinks: [
      {
        icon: "github",
        link: "https://github.com/fermeridamagni/school-resources",
      },
    ],

    search: {
      provider: "local",
    },

    editLink: {
      pattern:
        "https://github.com/fermeridamagni/school-resources/edit/main/docs/:path",
      text: "Edit this page on GitHub",
    },
  },
});
