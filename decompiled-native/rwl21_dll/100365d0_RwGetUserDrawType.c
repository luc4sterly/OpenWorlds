// 100365d0 RwGetUserDrawType [Global]
// program: RWL21.DLL

undefined4 RwGetUserDrawType(int param_1)

{
                    /* 0x365d0  270  RwGetUserDrawType */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x28);
  }
  FUN_1000cba0(1);
  return 0;
}


