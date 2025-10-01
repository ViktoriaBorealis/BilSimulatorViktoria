cmake_minimum_required(VERSION 4.0)
project(pekerenene)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
include(FetchContent)
set(THREEPP_BUILD_TESTS OFF)
set(THREEPP_BUILD_EXAMPLES OFF)
FetchContent_Declare(
        threepp
        GIT_REPOSITORY https://github.com/markaren/threepp.git
        GIT_TAG 619cdaacc2e7dc6ea709d8c7f482e2994af7349d
)
FetchContent_MakeAvailable(threepp)
add_executable(BilSimulator runProgram.cpp)
#add_executable(testy bareBones.cpp)

target_link_libraries(BilSimulator PUBLIC threepp::threepp)
#target_link_libraries(testy PUBLIC threepp::threepp)

#Bakgrunnsfarge til bestemt farge. Objekter skal starte blå, følge sinuskurve, Flytte kamera slik at vi faktsisk ser ting
#Trykke på knapp og "annenhver" skal bytte farge?
#Scene>Mesh>geometri>matrial
#Hvis du lager et material og bytter fargen på den så bytter alle som har det matriale farge

