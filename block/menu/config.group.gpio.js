module.exports = {
  name: "GPIO",
  index: 0,
  color: "230",
  icon: "/static/icons/icons8_electronics_96px.png",
  blocks: [
    {
      xml: `<sep gap="24"></sep><label text="IoT Device GPIO" web-class="headline"></label>`

    },
    "io_pin_dummy_input",
    "io_setpin_dummy_input",
  ]
};