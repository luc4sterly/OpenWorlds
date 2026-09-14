// 0040b030 FUN_0040b030 [Global]
// programa: gamma.dll

int __cdecl
FUN_0040b030(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)_Java_NET_worlds_console_IUnknown_getPtr_8(param_1,param_2);
  iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,param_3,param_4,param_5,param_6,param_7);
  if (iVar2 != 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e4a8,
                 s_IDispatch__GetIDsOfNames___faile_0046e520);
  }
  return iVar2;
}


