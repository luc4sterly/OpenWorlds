// 10008e50 RwGetFirstChildClump [Global]
// programa: RWL21.DLL

undefined4 RwGetFirstChildClump(int param_1)

{
                    /* 0x8e50  182  RwGetFirstChildClump */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x178);
  }
  FUN_1000cba0(1);
  return 0;
}


