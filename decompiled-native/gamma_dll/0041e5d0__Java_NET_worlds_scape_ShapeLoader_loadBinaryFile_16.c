// 0041e5d0 _Java_NET_worlds_scape_ShapeLoader_loadBinaryFile@16 [Global]
// program: gamma.dll

uint * _Java_NET_worlds_scape_ShapeLoader_loadBinaryFile_16
                 (int *param_1,undefined4 param_2,undefined4 param_3)

{
  LPCSTR pCVar1;
  uint *this;
  
                    /* 0x1e5d0  286  _Java_NET_worlds_scape_ShapeLoader_loadBinaryFile@16 */
  pCVar1 = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  this = FUN_0044e010(0x10);
  if (this != (uint *)0x0) {
    FUN_0041c970(this,param_1,pCVar1,param_2);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pCVar1);
  return this;
}


