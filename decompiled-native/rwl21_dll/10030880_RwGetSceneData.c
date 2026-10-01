// 10030880 RwGetSceneData [Global]
// program: RWL21.DLL

undefined4 RwGetSceneData(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x30880  239  RwGetSceneData */
  uVar1 = 0;
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x24);
  }
  return uVar1;
}


