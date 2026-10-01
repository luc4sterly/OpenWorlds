// 1000c0a0 RwGetCameraImage [Global]
// program: RWL21.DLL

undefined4 RwGetCameraImage(int param_1)

{
                    /* 0xc0a0  132  RwGetCameraImage */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x108);
  }
  FUN_1000cba0(1);
  return 0;
}


