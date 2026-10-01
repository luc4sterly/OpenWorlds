// 1000ee80 RwJointTransformBegin [Global]
// program: RWL21.DLL

bool __fastcall RwJointTransformBegin(undefined4 param_1,int param_2)

{
  int iVar1;
  
                    /* 0xee80  285  RwJointTransformBegin */
  iVar1 = FUN_1001d5c0(param_1,param_2,DAT_1005dfd0);
  return (bool)('\x01' - (iVar1 == 0));
}


