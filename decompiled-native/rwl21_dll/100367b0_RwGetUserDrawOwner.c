// 100367b0 RwGetUserDrawOwner [Global]
// program: RWL21.DLL

undefined4 RwGetUserDrawOwner(int param_1)

{
                    /* 0x367b0  267  RwGetUserDrawOwner */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x34);
  }
  FUN_1000cba0(1);
  return 0;
}


