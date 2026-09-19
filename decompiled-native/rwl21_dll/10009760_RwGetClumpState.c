// 10009760 RwGetClumpState [Global]
// programa: RWL21.DLL

undefined4 RwGetClumpState(int param_1)

{
                    /* 0x9760  166  RwGetClumpState */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 400);
  }
  FUN_1000cba0(1);
  return 0;
}


