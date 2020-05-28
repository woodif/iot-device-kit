let neopixel = require("./menu/config.group.neopixel");
let servo = require("./menu/config.group.servo");
let gpio = require("./menu/config.group.gpio");
let iot = require("./menu/config.group.iot");

module.exports = {
  //language=HTML format=false
  blocks: [
    gpio,
    neopixel,
    servo,
    iot,

    {
      override : true,
      name: "Time",
      index: 50,
      color: "230",
      icon: "/static/icons/icons8_Story_Time_96px.png",
      blocks: [
          {
              xml:
                  `<block type="time_delay">
                        <value name="delay">
                            <shadow type="math_number">
                                <field name="NUM">1000</field>
                            </shadow>
                        </value>
                    </block>`
          },
          {
              xml:
                  `<block type="time_delay_microsec">
                        <value name="delay">
                            <shadow type="math_number">
                                <field name="NUM">1000</field>
                            </shadow>
                        </value>
                    </block>`
          },
          "time_millis",
          "time_micros"
      ]
  },
  ],
};
