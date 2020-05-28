module.exports = function (Blockly) {
  "use strict";

  Blockly.Blocks['io_setpin_dummy_input'] = {
    init: function () {
      this.appendDummyInput()
        .appendField("set button pin 18");
      this.appendDummyInput()
        .appendField("as")
        .appendField(new Blockly.FieldDropdown([["INPUT_PULLUP_ONLY", "INPUT_PULLUP"]]), "mode");
      this.setInputsInline(true);
      this.setPreviousStatement(true, null);
      this.setNextStatement(true, null);
      this.setColour(45);
      this.setTooltip("set pin mode");
      this.setHelpUrl("");
    }
  };

  Blockly.Blocks["io_pin_dummy_input"] = {
    init: function () {
      this.appendDummyInput()
        .appendField(new Blockly.FieldDropdown([
          ["Built-In LED (IO22)", "22"],
          ["SW Active LOW (IO18)", "18"],
          ["Neopixel (IO4)", "4"],
          ["Servo (IO13)(TCK)", "13"]

        ]), "IO_PIN");
      this.setOutput(true, null);
      this.setColour(230);
      this.setTooltip("");
      this.setHelpUrl("");
    }
  };

};

