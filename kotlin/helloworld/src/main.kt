open class Person(var name: String, var language: Language = Language.EN){
    fun greet() = println("${language.greeting} $name")
}

enum class Language(val greeting: String){
    EN("Hello"), ES("Hola"), FR("Bonjour")
}

class Hispanophone(name: String) : Person(name, Language.ES)
class Francophone(name: String) : Person(name, Language.FR)


fun main(args: Array<String>) {
    var people = listOf(
        Person("Celia"),
        Hispanophone("Alice"),
        Francophone("Sam")
    )
    people.forEach { it.greet() }

    val name: String? = null
    println(name?.length)
}
