include_directories(../infoged)
# =========================
set(TT_TESTHEADERS fixture.h
    nodefixture.h
    )
set(TT_TESTSRC
    fixture.cpp
    main.cpp
    nodefixture.cpp
    test_addressstructure.cpp
    test_associatiobstructure.cpp
    test_changedate.cpp
    test_childtofamilylink.cpp
    test_eventdetail.cpp
    test_familyeventdetail.cpp
    test_familyeventstructure.cpp
    test_familyrecord.cpp
    test_gedcomline.cpp
    test_header.cpp
    test_individualattributestructure.cpp
    test_individualeventdetail.cpp
    test_individualeventstructure.cpp
    test_individualrecord.cpp
    test_indivordinance.cpp
    test_ldsindividualordinance.cpp
    test_ldsspousesealing.cpp
    test_linedata.cpp
    test_multimedialink.cpp
    test_multimediarecord.cpp
    test_multinode.cpp
    test_node.cpp
    test_notestructure.cpp
    test_personalnamepieces.cpp
    test_personalnamestructure.cpp
    test_place.cpp
    test_proxynode.cpp
    test_repositoryrecord.cpp
    test_sourcecitation.cpp
    test_sourcerecord.cpp
    test_sourcerepositorycitation.cpp
    test_spousetofamilylink.cpp
    test_stringutils.cpp
    test_submissionrecord.cpp
    test_submitterrecord.cpp
    test_token.cpp
    test_trailer.cpp
    test_entitymap.cpp
    test_tree.cpp
    test_misc.cpp

    
)

# ====================
add_executable(testinfoged ${TT_TESTSRC} ${TT_TESTHEADERS})
target_link_libraries(testinfoged ${INFO_LIBS})
# ==========================
