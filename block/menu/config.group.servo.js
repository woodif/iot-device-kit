const dirIcon = Vue.prototype.$global.board.board_info.dir;

module.exports = {
  name: "Servo Motor",
  index: 30,
  color: "230",
  icon: `file:///${dirIcon}/static/icons/servo.png`,
  blocks: [
     "esp32_servo_attach",
     "esp32_servo_detach",
     "esp32_servo_write",
     "esp32_servo_write_micros",
     "esp32_servo_read",
     "esp32_servo_read_micros"
  ]
};
