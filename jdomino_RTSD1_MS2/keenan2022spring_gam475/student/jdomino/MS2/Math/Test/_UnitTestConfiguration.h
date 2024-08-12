//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//-----------------------------------------------------------------------------  

#ifndef UNIT_TEST_CONFIGURATION_H
#define UNIT_TEST_CONFIGURATION_H

// Make sure all are enabled for final submission...
//      I grade whatever is set in this file - Keenan

#define Combo_VectLine                          true
#define Combo_VectCrossAddSub                   true
#define Combo_VectCrossAddSubMatrixMult         true
#define Combo_VectCrossAddSubMatrixMultCross    true
#define Combo_VectCrossCrossNorm                true
#define Combo_Junkfood                          true

#define Matrix_Accessor_Set                     true
#define Matrix_Accessor_Get_Const               true
#define Matrix_Accessor_Get                     true
#define Matrix_add_matrix                       true
#define Matrix_addEqual_matrix                  true
#define Matrix_sub_matrix                       true
#define Matrix_subEqual_matrix                  true
#define Matrix_Bracket_set                      true
#define Get_Brackets_const                      true
#define Matrix_Bracket_get                      true

#define MatrixRotOrient                         true
#define MatrixRotInverseOrient                  true
#define MatrixRotAxisAngle                      true
#define MatrixDestructor_constuctor             true
#define Matrix_copy_constructor                 true
#define Matrix_vector_constructor               true
#define Matrix_default_constructor              true
#define Matrix_det                              true
#define Matrix_Transpose                        true
#define Matrix_GetTranspose                     true
#define Matrix_AssignmentOperator               true
#define Matrix_inverse                          true
#define Matrix_getinverse                       true
#define Matrix_mult_matrix                      true
#define Matrix_multEqual_matrix                 true
#define Matrix_Scale                            true
#define Matrix_times_Scale                      true
#define Matrix_ScaleEquals                      true
#define Matrix_SET_Identity                     true
#define Matrix_SET_Zero                         true
#define Matrix_SET_Trans                        true
#define Matrix_SET_Trans_Vect                   true
#define Matrix_SET_SCALE                        true
#define Matrix_SET_SCALE_Vect                   true
#define Matrix_SET_RotX_SET                     true
#define Matrix_SET_RotY_SET                     true
#define Matrix_SET_RotZ_SET                     true
#define Matrix_SET_set_ROW_0                    true
#define Matrix_SET_set_ROW_1                    true
#define Matrix_SET_set_ROW_2                    true
#define Matrix_SET_set_ROW_3                    true
#define Matrix_SET_get_ROW_0                    true
#define Matrix_SET_get_ROW_1                    true
#define Matrix_SET_get_ROW_2                    true
#define Matrix_SET_get_ROW_3                    true
#define Matrix_SET_RotXYZ_SET                   true
#define Matrix_SET_MatrixRotAxisAngle_set       true
#define Matrix_SET_MatrixRotOrient_set          true
#define Matrix_SET_MatrixRotInverseOrient_set   true
#define Matrix_SET_isEqual_false                true
#define Matrix_SET_set_Vectors2                 true

#define Special_Matrix_Identity                 true
#define Special_Matrix_Zero                     true
#define Special_Matrix_Trans                    true
#define Special_Matrix_Trans_Vect               true
#define Special_Matrix_SCALE                    true
#define Special_Matrix_SCALE_Vect               true
#define Special_RotX                            true
#define Special_RotY                            true
#define Special_RotZ                            true
#define Special_isEqual_false2                  true
#define Special_RotXYZ_Constructor              true
#define Special_isEqual_true                    true
#define Special_isIdentity_false                true
#define Special_isIdentity_true                 true
#define Special_isRotation_false                true
#define Special_isRotation_true                 true

#define Matrix_UnaryPlus                        true
#define Matrix_unary_equal_Plus                 true
#define Matrix_UnaryMinus                       true
#define Matrix_unary_equal_Minus                true
									
#define Vect_Get_Accessors                      true
#define Vect_Get_Accessors_const                true
#define Vect_Set_Accessors                      true
#define Vect_Set_Accessors_get                  true												
#define Vect_Add_Vect                           true
#define Vect_plusEqual_Vect                     true
#define Vect_Sub_Vect                           true
#define Vect_SubEqual_Vect                      true
#define Vect_IsEqualFalse                       true
#define Vect_IsEqualTrue                        true
#define Vect_IsZeroFalse                        true
#define Vect_IsZeroTrue_True                    true
#define Vect_IsEqualFalse_default               true
#define Vect_IsEqualTrue_default                true
#define Vect_IsZeroFalse_default                true
#define Vect_IsZeroTrue_default                 true
#define Vect_Get_Brackets                       true
#define Vect_Get_Brackets_const                 true
#define Vect_Set_Brackets                       true
#define Vect_Set_Brackets_get                   true
#define Vect_default_constuctor                 true
#define Vect_individual_defaultW_constuctor     true
#define Vect_individual_constuctor              true
#define Vect_assignment_operator                true
#define Vect_Copy_constuctor                    true
#define Vect_Destructor_constuctor              true
#define Vect_Dot                                true
#define Vect_Cross                              true
#define Vect_Normalize                          true
#define Vect_GetNormalize                       true
#define Vect_Mag                                true
#define Vect_getAngle                           true				       
#define Vect_mult_matrix                        true
#define Vect_multEqual_matrix                   true							       
#define Vect_scale_Vect                         true
#define Vect_times_Scale                        true
#define Vect_ScaleEquals                        true						       
#define Vect_set_3_elements                     true
#define Vect_set_4_elements                     true
#define Vect_set_Vector                         true					       
#define Vect_SampleTest                         true
#define Vect_ConstantCheck                      true					       
#define Vect_unary_Plus                         true
#define Vect_unary_equal_Plus                   true
#define Vect_unary_Minus                        true
#define Vect_unary_equal_Minus                  true				       
     
#define Vect_Proxy_Mag                          true

#define	Trig_Cos                                true
#define Trig_Sin                                true
#define Trig_Tan                                true
#define Trig_ATan                               true
#define Trig_ATan2                              true
#define Trig_ACos                               true
#define Trig_ASin                               true
#define Trig_CosSin                             true
#define Trig_Sqrt                               true
#define Trig_InvSqrt                            true
										       
#endif

// ---  End of File ---------------
