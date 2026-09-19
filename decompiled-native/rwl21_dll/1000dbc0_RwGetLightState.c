// 1000dbc0 RwGetLightState [Global]
// programa: RWL21.DLL

undefined4 RwGetLightState(int param_1)

{
                    /* 0xdbc0  193  RwGetLightState */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x84);
  }
  FUN_1000cba0(1);
  return 0;
}


