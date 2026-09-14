// 004134f0 Java_NET_worlds_scape_WObject_getClumpBBox__LNET_worlds_scape_Point3Temp_2LNET_worlds_scape_Point3Temp_2 [Global]
// programa: gamma.dll

/* void __stdcall
   Java_NET_worlds_scape_WObject_getClumpBBox__LNET_worlds_scape_Point3Temp_2LNET_worlds_scape_Point3Temp_2(struct
   JNIEnv_ *,class _jobject *,class _jobject *,class _jobject *) */

void Java_NET_worlds_scape_WObject_getClumpBBox__LNET_worlds_scape_Point3Temp_2LNET_worlds_scape_Point3Temp_2
               (JNIEnv_ *param_1,_jobject *param_2,_jobject *param_3,_jobject *param_4)

{
  int iVar1;
  undefined4 local_24 [3];
  undefined4 local_18 [3];
  
                    /* 0x134f0  11
                       ?Java_NET_worlds_scape_WObject_getClumpBBox__LNET_worlds_scape_Point3Temp_2LNET_worlds_scape_Point3Temp_2@@YGXPAUJNIEnv_@@PAV_jobject@@11@Z
                        */
  iVar1 = (**(code **)(*(int *)param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 != 0) {
    FUN_00419360(iVar1,local_24,local_18);
    FUN_0041ab00((int *)param_1,param_3,local_24);
    FUN_0041ab00((int *)param_1,param_4,local_18);
  }
  return;
}


