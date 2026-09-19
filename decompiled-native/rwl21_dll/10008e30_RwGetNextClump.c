// 10008e30 RwGetNextClump [Global]
// programa: RWL21.DLL

undefined4 RwGetNextClump(int param_1)

{
                    /* 0x8e30  210  RwGetNextClump */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x184);
  }
  FUN_1000cba0(1);
  return 0;
}


