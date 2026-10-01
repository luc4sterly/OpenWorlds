// 004023f0 _Java_NET_worlds_core_RegKey_getReservedKey@12 [Global]
// program: gamma.dll

undefined4
_Java_NET_worlds_core_RegKey_getReservedKey_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_68 [100];
  
                    /* 0x23f0  143  _Java_NET_worlds_core_RegKey_getReservedKey@12 */
  switch(param_3) {
  case 0:
    return 0x80000000;
  case 1:
    return 0x80000001;
  case 2:
    return 0x80000002;
  case 3:
    return 0x80000003;
  default:
    FUN_0044d650((int)local_68,s_Key_not_found___d_0046d2ac);
    FUN_00402930(param_1,(byte *)s_NET_worlds_core_RegKeyNotFoundEx_0046d2c0,local_68);
    return 0;
  }
}


