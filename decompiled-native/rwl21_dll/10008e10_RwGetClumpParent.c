// 10008e10 RwGetClumpParent [Global]
// programa: RWL21.DLL

undefined4 RwGetClumpParent(int param_1)

{
                    /* 0x8e10  164  RwGetClumpParent */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x174);
  }
  FUN_1000cba0(1);
  return 0;
}


