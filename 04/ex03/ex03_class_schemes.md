# C++ Module 04, Exercise 03: Interface & Recap

## Visual class relationship schemes

These schemes show how the classes in `ex03` are connected: interfaces, abstract class, concrete classes, inventory, and materia source.

---

## 1. `AMateria`, `Ice`, and `Cure`

```text
                    ┌──────────────────────┐
                    │      AMateria         │
                    │  abstract class       │
                    ├──────────────────────┤
                    │ - type: std::string   │
                    ├──────────────────────┤
                    │ + getType()           │
                    │ + clone() = 0         │
                    │ + use(ICharacter&)    │
                    └───────────▲──────────┘
                                │
                 inherits       │       inherits
                ┌───────────────┴───────────────┐
                │                               │
        ┌──────────────┐                ┌──────────────┐
        │     Ice      │                │     Cure     │
        ├──────────────┤                ├──────────────┤
        │ type = "ice" │                │ type = "cure"│
        ├──────────────┤                ├──────────────┤
        │ + clone()    │                │ + clone()    │
        │ + use()      │                │ + use()      │
        └──────────────┘                └──────────────┘
```

### Meaning

- `AMateria` is an abstract base class.
- `Ice` and `Cure` inherit from `AMateria`.
- `clone()` is pure virtual in `AMateria`, so every concrete materia must implement it.
- `Ice::clone()` returns a new `Ice`.
- `Cure::clone()` returns a new `Cure`.

---

## 2. `ICharacter` and `Character`

```text
                    ┌────────────────────────┐
                    │      ICharacter        │
                    │      interface         │
                    ├────────────────────────┤
                    │ + getName() = 0        │
                    │ + equip() = 0          │
                    │ + unequip() = 0        │
                    │ + use() = 0            │
                    └───────────▲────────────┘
                                │ implements
                                │
                    ┌────────────────────────┐
                    │       Character        │
                    ├────────────────────────┤
                    │ - name: std::string    │
                    │ - inventory[4]         │
                    │   AMateria*            │
                    ├────────────────────────┤
                    │ + equip(AMateria*)     │
                    │ + unequip(int)         │
                    │ + use(int, target)     │
                    └───────────┬────────────┘
                                │
                                │ has 4 slots
                                ▼
                    ┌────────────────────────┐
                    │ inventory[4]           │
                    ├────────────────────────┤
                    │ [0] AMateria*          │
                    │ [1] AMateria*          │
                    │ [2] AMateria*          │
                    │ [3] AMateria*          │
                    └────────────────────────┘
```

### Meaning

- `ICharacter` is an interface.
- `Character` implements `ICharacter`.
- `Character` has an inventory with 4 slots.
- Every slot stores an `AMateria*`.
- The real object inside the slot can be `Ice`, `Cure`, or any other class inherited from `AMateria`.

---

## 3. `IMateriaSource` and `MateriaSource`

```text
                    ┌────────────────────────────┐
                    │      IMateriaSource        │
                    │        interface           │
                    ├────────────────────────────┤
                    │ + learnMateria() = 0       │
                    │ + createMateria() = 0      │
                    └────────────▲───────────────┘
                                 │ implements
                                 │
                    ┌────────────────────────────┐
                    │       MateriaSource        │
                    ├────────────────────────────┤
                    │ - templates[4]             │
                    │   AMateria*                │
                    ├────────────────────────────┤
                    │ + learnMateria(AMateria*)  │
                    │ + createMateria(type)      │
                    └────────────┬───────────────┘
                                 │ stores clones as templates
                                 ▼
                    ┌────────────────────────────┐
                    │ templates[4]               │
                    ├────────────────────────────┤
                    │ [0] Ice* / Cure*           │
                    │ [1] Ice* / Cure*           │
                    │ [2] Ice* / Cure*           │
                    │ [3] Ice* / Cure*           │
                    └────────────────────────────┘
```

### Meaning

- `IMateriaSource` is an interface.
- `MateriaSource` implements `IMateriaSource`.
- `MateriaSource` remembers up to 4 materia templates.
- `createMateria("ice")` creates a new cloned `Ice` if `Ice` was learned before.
- `createMateria("cure")` creates a new cloned `Cure` if `Cure` was learned before.
- If the type is unknown, `createMateria()` returns `0`.

---

## 4. General project flow

```text
              ┌───────────────────┐
              │   MateriaSource   │
              │ knows templates   │
              └─────────┬─────────┘
                        │
                        │ createMateria("ice")
                        │ createMateria("cure")
                        ▼
              ┌───────────────────┐
              │    AMateria*      │
              │ actually Ice/Cure │
              └─────────┬─────────┘
                        │
                        │ equip()
                        ▼
              ┌───────────────────┐
              │    Character      │
              │ inventory[4]      │
              └─────────┬─────────┘
                        │
                        │ use(index, target)
                        ▼
              ┌───────────────────┐
              │ AMateria::use()   │
              │ on target         │
              └───────────────────┘
```

### Meaning

The flow is:

```text
learnMateria(new Ice())
        ↓
MateriaSource stores template Ice

createMateria("ice")
        ↓
returns new Ice clone

me->equip(tmp)
        ↓
Character stores AMateria* in inventory

me->use(0, bob)
        ↓
inventory[0]->use(bob)
        ↓
Ice prints: shoots ice bolt at bob
```

---

## 5. Short explanation for evaluation

```text
AMateria is an abstract base class for all Materias.
Ice and Cure inherit from AMateria and implement clone() and use().
ICharacter is an interface for characters.
Character implements ICharacter and stores up to 4 AMateria pointers in inventory.
IMateriaSource is an interface for a materia factory.
MateriaSource implements IMateriaSource, learns materia templates, and creates new materia objects by cloning them.
```

---

## 6. What is important to remember

```text
AMateria* pointer can point to Ice or Cure.
This is polymorphism.

ICharacter* pointer can point to Character.
This is interface usage.

IMateriaSource* pointer can point to MateriaSource.
This is also interface usage.

clone() is needed to create a new independent copy of the same materia type.

Character must make deep copies of its inventory.
MateriaSource must also manage memory carefully.
unequip() must not delete the materia.
```
