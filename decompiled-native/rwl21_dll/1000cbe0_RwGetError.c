// 1000cbe0 RwGetError [Global]
// program: RWL21.DLL

undefined4 RwGetError(void)

{
  undefined4 uVar1;
  
                    /* 0xcbe0  181  RwGetError */
  uVar1 = DAT_1005a0a4;
  DAT_1005a0a4 = 0;
  return uVar1;
}


