// 10030e10 RwGetClumpAxisAlignment [Global]
// programa: RWL21.DLL

undefined4 RwGetClumpAxisAlignment(int param_1)

{
                    /* 0x30e10  146  RwGetClumpAxisAlignment */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x18c);
  }
  FUN_1000cba0(1);
  return 0;
}


